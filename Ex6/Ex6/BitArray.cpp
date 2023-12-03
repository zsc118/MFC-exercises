#include "stdafx.h"
#include "BitArray.h"

CBitArray::~CBitArray()
{
    if (m_data)
        free(m_data);
}

void CBitArray::push(bool value)
{
    if (top_pointer <<= 1)
    {
        if (value)
            *m_top |= top_pointer;
        return;
    }
    top_pointer = '\1';
    if (!m_data)
    {
        *(m_top = m_data = (uint8_t *)malloc(1)) = value ? '\1' : '\0';
        return;
    }
    uint8_t *pre(m_data), *P(pre);
    size_t n(m_top - m_data + 2);
    *(m_top = m_data = (uint8_t *)malloc(n--)) = *pre;
    while (--n)
        *++m_top = *++pre;
    *++m_top = value ? '\1' : '\0';
    free(P);
}

void CBitArray::pop()
{
    if(top_pointer>>=1)
        return;
    if(m_data!=m_top)
    {
        top_pointer = '\200';
        --m_top;
        return;
    }
    free(m_data);
    top_pointer = '\0';
    m_data = m_top = nullptr;
}
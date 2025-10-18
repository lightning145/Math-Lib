#include <MD_Math.h>
#include <Constant.h>
#include <stdio.h>

mdMat MatAdd(mdMat m1, mdMat m2)
{
    mdMat result;
    int i;
    for (i = 0; i < 16; i++)
    {
        result.coords[i] = m1.coords[i] + m2.coords[i];
    }
    
    return result;
}

mdMat MatMinus(mdMat m1, mdMat m2)
{
    mdMat result;
    int i;
    for (i = 0; i < 16; i++)
    {
        result.coords[i] = m1.coords[i] - m2.coords[i];
    }
    
    return result;
}

mdMat MulMat(float lambda, mdMat m)
{
    mdMat result;
    int i;
    for (i = 0; i < 16; i++)
    {
        result.coords[i] = lambda * m.coords[i];
    }
    
    return result;
}

mdMat MatMul(mdMat m1, mdMat m2)
{
    mdMat result;
    mdVec4 temp1, temp2;
    int i, j;
    for ( i = 0; i < 4; i++)
    {
        temp1.x = m1.coords[4 * i];
        temp1.y = m1.coords[4 * i + 1];
        temp1.z = m1.coords[4 * i + 2];
        temp1.w = m1.coords[4 * i + 3];

        for ( j = 0; j < 4; j++)
        {
            temp2.x = m2.coords[j];
            temp2.y = m2.coords[j + 4];
            temp2.z = m2.coords[j + 8];
            temp2.w = m2.coords[j + 12];
            result.ij[i][j] = Vec4Dot(temp1, temp2);
        }
        
    }
    
    return result;
}

int MatEqual(mdMat m1, mdMat m2)
{
    return (
        MD_Equal(m1.coords[0], m2.coords[0]) &&
        MD_Equal(m1.coords[1], m2.coords[1]) &&
        MD_Equal(m1.coords[2], m2.coords[2]) &&
        MD_Equal(m1.coords[3], m2.coords[3]) &&

        MD_Equal(m1.coords[4], m2.coords[4]) &&
        MD_Equal(m1.coords[5], m2.coords[5]) &&
        MD_Equal(m1.coords[6], m2.coords[6]) &&
        MD_Equal(m1.coords[7], m2.coords[7]) &&

        MD_Equal(m1.coords[8], m2.coords[8]) &&
        MD_Equal(m1.coords[9], m2.coords[9]) &&
        MD_Equal(m1.coords[10], m2.coords[10]) &&
        MD_Equal(m1.coords[11], m2.coords[11]) &&

        MD_Equal(m1.coords[12], m2.coords[12]) &&
        MD_Equal(m1.coords[13], m2.coords[13]) &&
        MD_Equal(m1.coords[14], m2.coords[14]) &&
        MD_Equal(m1.coords[15], m2.coords[15]) 
    ) ? MD_TRUE : MD_FALSE;
}

mdVec4 MulVec(mdMat m, mdVec4 v)
{
    mdVec4 result, temp;
    int i;
    for ( i = 0; i < 4; i++)
    {
        temp.x = v.coords[0] * m.coords[4 * i];
        temp.y = v.coords[1] * m.coords[4 * i + 1];
        temp.z = v.coords[2] * m.coords[4 * i + 2];
        temp.w = v.coords[3] * m.coords[4 * i + 3];
        
        result.coords[i] = temp.x + temp.y + temp.z + temp.w;
    }
    
    return result;
}

mdMat IdentityMat()
{
    mdMat id = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    return id;
};

mdMat TransposeMat(mdMat m)
{
    mdMat result;
    int i, j;
    for ( i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            result.ij[i][j] = m.ij[j][i];
        }
    }
    
    return result;
}

//----------Tool Sturct And Function----------
typedef struct MATRIX2x2
{        
    float _11, _12, 
          _21, _22;
} MATRIX2x2;

typedef struct MATRIX3x3
{
    float _11, _12, _13,
          _21, _22, _23,
          _31, _32, _33;
} MATRIX3x3;

float DetMatrix2x2(MATRIX2x2 m)
{
    return m._11 * m._22 - m._12 * m._21;
}

float DetMatrix3x3(MATRIX3x3 m)
{
    MATRIX2x2 m1 = {m._22,m._23,
                    m._32,m._33};

    MATRIX2x2 m2 = {m._21,m._23,
                    m._31,m._33};

    MATRIX2x2 m3 = {m._21,m._22,
                    m._31,m._32};

    return m._11 * DetMatrix2x2(m1) - m._12 * DetMatrix2x2(m2) + m._13 * DetMatrix2x2(m3);  
}

//--------------------------------------------

float DetMat(mdMat m)
{
    MATRIX3x3 m1 = {m._22,m._23,m._24,
                    m._32,m._33,m._34,
                    m._42,m._43,m._44};       

    MATRIX3x3 m2 = {m._21,m._23,m._24,
                    m._31,m._33,m._34,
                    m._41,m._43,m._44};

    MATRIX3x3 m3 = {m._21,m._22,m._24,
                    m._31,m._32,m._34,
                    m._41,m._42,m._44};      

    MATRIX3x3 m4 = {m._21,m._22,m._23,
                    m._31,m._32,m._33,
                    m._41,m._42,m._43};

    return m._11 * DetMatrix3x3(m1) - m._12 * DetMatrix3x3(m2) + m._13 * DetMatrix3x3(m3) - m._14 *DetMatrix3x3(m4);
}

mdMat AdjointMat(mdMat m)
{
    mdMat rm;
    mdMat adj;      
 
    MATRIX3x3 m1 = {m._22, m._23,m._24,
                        m._32,m._33,m._34,
                        m._42,m._43,m._44};
    MATRIX3x3 m2 = {m._21,m._23,m._24,
                        m._31,m._33,m._34,
                        m._41,m._43,m._44};
    MATRIX3x3 m3 = {m._21,m._22,m._24,
                        m._31,m._32,m._34,
                        m._41,m._42,m._44};
    MATRIX3x3 m4 = {m._21,m._22,m._23,
                        m._31,m._32,m._33,
                        m._41,m._42,m._43};

    MATRIX3x3 m5 = {m._12,m._13,m._14,
                        m._32,m._33,m._34,
                        m._42,m._43,m._44};
    MATRIX3x3 m6 = {m._11,m._13,m._14,
                        m._31,m._33,m._34,
                        m._41,m._43,m._44};
    MATRIX3x3 m7 = {m._11,m._12,m._14,
                        m._31,m._32,m._34,
                        m._41,m._42,m._44};
    MATRIX3x3 m8 = {m._11,m._12,m._13,
                        m._31,m._32,m._33,
                        m._41,m._42,m._43};

    MATRIX3x3 m9 = {m._12,m._13,m._14,
                        m._22,m._23,m._24,
                        m._42,m._43,m._44};
    MATRIX3x3 m10 = {m._11, m._13, m._14,
                     m._21, m._23, m._24,
                     m._41, m._43, m._44}; 
    MATRIX3x3 m11 = {m._11,m._12,m._14,
                        m._21,m._22,m._24,
                        m._41,m._42,m._44};
    MATRIX3x3 m12 = {m._11,m._12,m._13,
                        m._21,m._22,m._23,
                        m._41,m._42,m._43};

    MATRIX3x3 m13 = {m._12,m._13,m._14,
                        m._22,m._23,m._24,
                        m._32,m._33,m._34};
    MATRIX3x3 m14 = {m._11,m._13,m._14,
                        m._21,m._23,m._24,
                        m._31,m._33,m._34};
    MATRIX3x3 m15 = {m._11,m._12,m._14,
                        m._21,m._22,m._24,
                        m._31,m._32,m._34};
    MATRIX3x3 m16 = {m._11,m._12,m._13,
                        m._21,m._22,m._23,
                        m._31,m._32,m._33};

    rm._11 = DetMatrix3x3(m1);
    rm._12 = (-1) * DetMatrix3x3(m2);
    rm._13 = DetMatrix3x3(m3);
    rm._14 = (-1) * DetMatrix3x3(m4);

    rm._21 = (-1) * DetMatrix3x3(m5);
    rm._22 = DetMatrix3x3(m6);
    rm._23 = (-1) * DetMatrix3x3(m7);
    rm._24 = DetMatrix3x3(m8);

    rm._31 = DetMatrix3x3(m9);
    rm._32 = (-1) * DetMatrix3x3(m10);
    rm._33 = DetMatrix3x3(m11);
    rm._34 = (-1) * DetMatrix3x3(m12);

    rm._41 = (-1) * DetMatrix3x3(m13);
    rm._42 = DetMatrix3x3(m14);
    rm._43 = (-1) * DetMatrix3x3(m15);
    rm._44 = DetMatrix3x3(m16);

    adj._11 = rm._11;
    adj._12 = rm._21;
    adj._13 = rm._31;
    adj._14 = rm._41;

    adj._21 = rm._12;
    adj._22 = rm._22;
    adj._23 = rm._32;
    adj._24 = rm._42;

    adj._31 = rm._13;
    adj._32 = rm._23;
    adj._33 = rm._33;
    adj._34 = rm._43;

    adj._41 = rm._14;
    adj._42 = rm._24;
    adj._43 = rm._34;
    adj._44 = rm._44;

    return adj;
}

mdMat InvMat(mdMat m)
{
    mdMat Inv,adj;
   
    float det = DetMat(m);

    float _1det = 1.0f / det;
    adj = AdjointMat(m);

    Inv = MulMat(_1det, adj);
    
    return Inv;
}
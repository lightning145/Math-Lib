#ifndef MD_MATRIX_H
#define MD_MATRIX_H

typedef struct mdMat
{
    union 
    {
        float coords[16];
        float ij[4][4];
        struct 
        {
            float _11, _12, _13, _14,
                  _21, _22, _23, _24,
                  _31, _32, _33, _34,
                  _41, _42, _43, _44;
        };  
    };
    
} mdMat;

#endif

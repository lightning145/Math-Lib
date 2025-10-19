#ifndef MD_QUATERNION
#define MD_QUATERNION

typedef struct mdQuat
{
    union 
    {
        float coords[4];
        struct 
        {
            float a, b, c, d;
        };
        
    };
        
} mdQuat;

#endif
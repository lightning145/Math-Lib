typedef struct mdVec2
{
    union 
    {
        float coords[2];
        struct 
        {
            float x, y;
        };
        
    };
    
} mdVec2;

typedef struct mdVec3
{
    union 
    {
        float coords[3];
        struct 
        {
            float x, y, z;
        };
        
    };
    
} mdVec3;

typedef struct mdVec4
{
    union 
    {
        float coords[4];
        struct 
        {
            float x, y, z, w;
        };
        
    };
    
} mdVec4;

typedef struct mdIVec4 { // Just For Assimp
    int x, y, z, w;
} IVECTOR4;

typedef struct mdIVec2 { // Just For FreeType
    int x, y;
} IVECTOR2;
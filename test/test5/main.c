#include <MD_Math.h>
#include <windows.h>
#include "glad.h"

HWND windowHandle = NULL;
WNDCLASS wc;
HDC hDC; 
HGLRC hRC;
unsigned int shaderProgram;

void Init(HINSTANCE instanceHanled, int show);

void Shader_SetInt(const char* name, int value);
void Shader_SetFloat(const char* name, float value);
void Shader_SetVec2(const char* name, mdVec2 value);
void Shader_SetVec3(const char* name, mdVec3 value);
void Shader_SetVec4(const char* name, mdVec4 value);
void Shader_SetMatrix(const char* name, mdMat value);

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
    Init(hinstance, showCmd);

    float lastTime = (float)timeGetTime(); 

    hDC = GetDC(windowHandle);
	
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd  
		1,                                // version number  
		PFD_DRAW_TO_WINDOW |              // support window  
		PFD_SUPPORT_OPENGL |              // support OpenGL  
		PFD_DOUBLEBUFFER,                 // double buffered  
		PFD_TYPE_RGBA,                    // RGBA type  
		24,                               // 24-bit color depth  
		0, 0, 0, 0, 0, 0,                 // color bits ignored  
		0,                                // no alpha buffer  
		0,                                // shift bit ignored  
		0,                                // no accumulation buffer  
		0, 0, 0, 0,                       // accum bits ignored  
		32,                               // 32-bit z-buffer      
		0,                                // no stencil buffer  
		0,                                // no auxiliary buffer  
		PFD_MAIN_PLANE,                   // main layer  
		0,                                // reserved  
		0, 0, 0                           // layer masks ignored  
	};
	int iPixelFormat = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, iPixelFormat, &pfd);
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);
	
	gladLoadGL();

    MSG msg;

    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "uniform vec3 color;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(color, 1.0f);\n"
    "}\0";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    float vertices[] = {
    -0.1f, -0.1f, 0.0f,
     0.1f, -0.1f, 0.0f,
     0.0f,  0.1f, 0.0f
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    float x = 0.0f, y = 0.0f, z = 0.0f;
    float s = 0.1f;

    while (1)
    {
        if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            if(msg.message == WM_QUIT)
                break;

            TranslateMessage(&msg);
            DispatchMessage(&msg);     
        }
        else
        {
            if(GetAsyncKeyState(VK_ESCAPE) & 0x8000f )
                break;

            float currTime  = (float)timeGetTime();
			float timeDelta = (currTime - lastTime)*0.001f;

            mdVec3 cameraPos = {0.0f, 0.0f, 2.0f};
            mdVec3 cameraFront = {0.0f, 0.0f, -1.0f};
            mdVec3 cameraUp = {0.0f, 1.0f, 0.0f};
            mdMat View = ViewMatrixRH(cameraPos, cameraFront, cameraUp);

            if(GetAsyncKeyState('W') & 0x8000f )
            {

            }

			if(GetAsyncKeyState('S') & 0x8000f )
            {
  
            }

			if(GetAsyncKeyState('A') & 0x8000f )
            {
   
            }

			if(GetAsyncKeyState('D') & 0x8000f )
            {
              
            }
                
            if(GetAsyncKeyState(VK_LEFT) & 0x8000f )
            {

            }

			if(GetAsyncKeyState(VK_RIGHT) & 0x8000f )
            {

            }

			if(GetAsyncKeyState(VK_UP) & 0x8000f )
            {

            }

			if(GetAsyncKeyState(VK_DOWN) & 0x8000f )
            {

            }

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUseProgram(shaderProgram);
            mdVec3 color = {0.0f, 1.0f, 0.0f};
            Shader_SetVec3("color", color);

            mdVec3 pos = {0.0f, 0.0f, 0.0f};
            mdVec3 scale = {1.0f, 1.0f, 1.0f};
            mdMat model = MatMul(TranslationMatrix(pos), ScaleMatrix(scale));
            Shader_SetMatrix("model", model);

            Shader_SetMatrix("view", View);

           mdMat proj = PerspcetiveMatrixRH(MD_ToRadian(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
           glUniformMatrix4fv(
            glGetUniformLocation(shaderProgram, "projection"),
             1,
             GL_FALSE,
            proj.coords);

            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            SwapBuffers(hDC);
	        Sleep(1);

            lastTime = currTime;
        }
    }
    
    glDeleteProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(windowHandle, hDC);
    UnregisterClass("Window Class", hinstance);
    DestroyWindow(windowHandle);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd,
                        UINT msg,
                        WPARAM wParam,
                        LPARAM lParam)
{
    switch(msg)
    {

    case WM_DESTROY:

        PostQuitMessage(0);
        break;

    default:
        break;

    }

    return DefWindowProc(
        hWnd,
        msg,
        wParam,
        lParam
    );
}

void Init(HINSTANCE instanceHanled, int show)
{
    wc.style = CS_HREDRAW|CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = instanceHanled;
    //wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    //wc.hCursor = LoadCursor(0, IDC_ARROW);
    //wc.hbrBackground = (HBRUSH)(GetStockObject(BLACK_BRUSH));
    wc.lpszMenuName = 0;
    wc.lpszClassName = "Window Class";

    RegisterClass(&wc);

    windowHandle = CreateWindowA(
        "Window Class",
        "Test 5 - OpenGL",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        0,
        0,
        instanceHanled,
        0
    );

    LONG style = GetWindowLong(windowHandle, GWL_STYLE); 

    style &= ~(WS_MAXIMIZEBOX | WS_THICKFRAME);
    SetWindowLong(windowHandle, GWL_STYLE, style);

    ShowWindow(windowHandle,show);
    UpdateWindow(windowHandle);
    
}

void Shader_SetInt(const char* name, int value)
{
    glUniform1i(glGetUniformLocation(shaderProgram, name), value);
}

void Shader_SetFloat(const char* name, float value)
{
    glUniform1f(glGetUniformLocation(shaderProgram, name), value);
}

void Shader_SetVec2(const char* name, mdVec2 value)
{
    glUniform2f(glGetUniformLocation(shaderProgram, name), value.x, value.y);
}

void Shader_SetVec3(const char* name, mdVec3 value)
{
    glUniform3f(glGetUniformLocation(shaderProgram, name), value.x, value.y,value.z);
}

void Shader_SetVec4(const char* name, mdVec4 value)
{
    glUniform4f(glGetUniformLocation(shaderProgram, name), value.x, value.y,value.z, value.w);
}

void Shader_SetMatrix(const char* name, mdMat value)
{
    glUniformMatrix4fv(
        glGetUniformLocation(shaderProgram, name),
        1,
        GL_FALSE,
        value.coords);
}
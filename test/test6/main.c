#include <MD_Math.h>
#include <windows.h>

#include <d3d9.h>
#include <d3dx9.h>

HWND windowHandle = NULL;
WNDCLASS wc;

IDirect3D9* d3d9;
IDirect3DDevice9* device;

IDirect3DVertexBuffer9* VB;
IDirect3DIndexBuffer9*  IB;

void Init(HINSTANCE instanceHanled, int show);

typedef struct Vertex
{
	float _x, _y, _z;
	D3DCOLOR _color;
} Vertex;

const DWORD FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;

D3DMATRIX* mdToD3D(mdMat m);

int WINAPI WinMain(HINSTANCE hinstance,
				   HINSTANCE prevInstance, 
				   PSTR cmdLine,
				   int showCmd)
{
    Init(hinstance, showCmd);

    float lastTime = (float)timeGetTime(); 

    d3d9 = Direct3DCreate9(D3D_SDK_VERSION);

    D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth            = 800;
	d3dpp.BackBufferHeight           = 600;
	d3dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount            = 1;
	d3dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality         = 0;
	d3dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
	d3dpp.hDeviceWindow              = windowHandle;
	d3dpp.Windowed                   = 1;
	d3dpp.EnableAutoDepthStencil     = 1; 
	d3dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
	d3dpp.Flags                      = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;

    d3d9->lpVtbl->CreateDevice(
        d3d9,
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        windowHandle,
        D3DCREATE_HARDWARE_VERTEXPROCESSING,
        &d3dpp,
        &device
    );

    device->lpVtbl->CreateVertexBuffer(device, 
    3 * sizeof(Vertex), 
    D3DUSAGE_WRITEONLY, 
    FVF, 
    D3DPOOL_MANAGED, 
    &VB, 
    NULL);

device->lpVtbl->CreateIndexBuffer(device,
    3 * sizeof(WORD),
    D3DUSAGE_WRITEONLY,
    D3DFMT_INDEX16,
    D3DPOOL_MANAGED,
    &IB,
    NULL);

    MSG msg;

    Vertex* vertices;
	VB->lpVtbl->Lock(VB, 0, 0, (void**)&vertices, 0);

	vertices[0]._x = 0.0f;
    vertices[0]._y = 0.1f;
    vertices[0]._z = 0.0f;
    vertices[0]._color = D3DCOLOR_XRGB(255, 0, 0);
    
    vertices[1]._x = 0.1f;
    vertices[1]._y = 0.0f;
    vertices[1]._z = 0.0f;
    vertices[1]._color = D3DCOLOR_XRGB(0, 255, 0);

    vertices[2]._x = -0.1f;
    vertices[2]._y = 0.0f;
    vertices[2]._z = 0.0f;
    vertices[2]._color = D3DCOLOR_XRGB(0, 0, 255);

	VB->lpVtbl->Unlock(VB);

	WORD* indices = 0;
	IB->lpVtbl->Lock(IB, 0, 0, (void**)&indices, 0);

	indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;

	IB->lpVtbl->Unlock(IB);

    float x = 0.0f, y = 0.0f, z = 0.0f;
    float s = 0.1f;

    device->lpVtbl->SetRenderState(device, D3DRS_LIGHTING, 0);
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

            mdVec3 cameraPos = {0.0f, 0.0f, -2.0f};
            mdVec3 cameraFront = {0.0f, 0.0f, 1.0f};
            mdVec3 cameraUp = {0.0f, 1.0f, 0.0f};
            mdMat View = ViewMatrixLH(cameraPos, cameraFront, cameraUp);

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

            mdVec3 color = {0.0f, 1.0f, 0.0f};

            mdVec3 pos = {0.0f, 0.0f, 0.0f};
            mdVec3 scale = {5.0f, 5.0f, 5.0f};
            mdMat model = MatMul(TranslationMatrix(pos), ScaleMatrix(scale));
            device->lpVtbl->SetTransform(device, D3DTS_WORLD, mdToD3D(model));

           mdMat proj = PerspcetiveMatrixLH(MD_ToRadian(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
     
           device->lpVtbl->SetTransform(device, D3DTS_VIEW, mdToD3D(View));

           device->lpVtbl->SetTransform(device, D3DTS_PROJECTION, mdToD3D(proj));

           device->lpVtbl->Clear(device, 0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255,0,0), 1.0f, 0);

        device->lpVtbl->BeginScene(device);

		    device->lpVtbl->SetStreamSource(device, 0, VB, 0, sizeof(Vertex));
		    device->lpVtbl->SetIndices(device, IB);
		    device->lpVtbl->SetFVF(device,FVF);

		    device->lpVtbl->DrawIndexedPrimitive(device, D3DPT_TRIANGLELIST, 0, 0, 3, 0, 1);
 
		    device->lpVtbl->EndScene(device);

           device->lpVtbl->Present(device, 0, 0, 0, 0);

            lastTime = currTime;
        }
    }
 
    VB->lpVtbl->Release(VB);
    IB->lpVtbl->Release(IB);
    d3d9->lpVtbl->Release(d3d9);
    device->lpVtbl->Release(device);
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
        "Test 6 - Direct3D 9",
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

D3DMATRIX* mdToD3D(mdMat m)
{
    static D3DMATRIX out;
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            out.m[i][j] = m.ij[i][j];
        }
    }
    return &out;
}
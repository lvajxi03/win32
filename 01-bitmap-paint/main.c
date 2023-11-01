#include <windows.h>
#include "resources.h"
// #include <gdiplus.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  MSG msg          = {0};
  WNDCLASS wc      = {0};
  wc.lpfnWndProc   = WndProc;
  wc.hInstance     = hInstance;
  wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wc.lpszClassName = L"SampleBitmapPaintInWin32World";
  if(!RegisterClass(&wc))
  {
    MessageBox( NULL, L"Cannot register windows class", L"Error", MB_OK | MB_ICONEXCLAMATION);
    return 1;
  }
  if(!CreateWindow(wc.lpszClassName,
                   L"Sample bitmap paint in win32 world",
                   WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   0,
                   0,
                   hInstance,
                   NULL))
  {
    MessageBox( NULL, L"Cannot create window!", L"Error", MB_OK | MB_ICONEXCLAMATION);
    return 1;
  }
  while (GetMessage(&msg, NULL, 0, 0) > 0)
  {
    DispatchMessage(&msg);
  }
  return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  HDC wdc = GetDC(hWnd);
  HINSTANCE hInstance = GetModuleHandle(NULL);
  HBITMAP bitmap;
  PAINTSTRUCT ps;
  RECT r;
  switch(message)
  {
    case WM_CREATE:
      {
        break;
      }
    case WM_PAINT:
      {
	BITMAP bmp;
        GetClientRect(hWnd, &r);
        bitmap = LoadBitmap(hInstance, MAKEINTRESOURCE(IDB_BITMAP_1));
        HDC hdc = BeginPaint(hWnd, &ps);
        HDC memDC = CreateCompatibleDC(hdc);
        GetObject(bitmap, sizeof(BITMAP), (LPSTR)&bmp);
        FillRect(hdc, &r, (HBRUSH) (COLOR_WINDOW+1));
        SelectObject(memDC, bitmap);
        StretchBlt(hdc, r.right - 480, r.bottom - 360, 480, 360, memDC, 0, 0, 480, 360, SRCCOPY);
        DeleteDC(memDC);
        EndPaint(hWnd, &ps);
        break;
      }
    case WM_SIZE:
      {
        // InvalidateRect(hWnd, NULL, TRUE);
        break;
      }
    case WM_CLOSE:
      {
        DeleteDC(wdc);
        PostQuitMessage(0);
        break;
      }
    default:
      {
        return DefWindowProc(hWnd, message, wParam, lParam);
      }
  }
  return 0;
}

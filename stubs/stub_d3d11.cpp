// D3D11 Forwarding Stub
// Redireciona chamadas para D3D11.dll real em vez de stub vazio
#include <d3d11.h>
#include <windows.h>

// ---------------------------------------------------------------------------
// D3D11CreateDevice
// ---------------------------------------------------------------------------
typedef HRESULT(WINAPI *D3D11CreateDevice_t)(
    IDXGIAdapter *pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software,
    UINT Flags, const D3D_FEATURE_LEVEL *pFeatureLevels, UINT FeatureLevels,
    UINT SDKVersion, ID3D11Device **ppDevice, D3D_FEATURE_LEVEL *pFeatureLevel,
    ID3D11DeviceContext **ppImmediateContext);

HRESULT WINAPI stub_D3D11CreateDevice(
    IDXGIAdapter *pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software,
    UINT Flags, const D3D_FEATURE_LEVEL *pFeatureLevels, UINT FeatureLevels,
    UINT SDKVersion, ID3D11Device **ppDevice, D3D_FEATURE_LEVEL *pFeatureLevel,
    ID3D11DeviceContext **ppImmediateContext) {
  static D3D11CreateDevice_t realFunc = (D3D11CreateDevice_t)GetProcAddress(
      LoadLibraryA("d3d11.dll"), "D3D11CreateDevice");
  return realFunc(pAdapter, DriverType, Software, Flags, pFeatureLevels,
                  FeatureLevels, SDKVersion, ppDevice, pFeatureLevel,
                  ppImmediateContext);
}

// ---------------------------------------------------------------------------
// D3D11CreateDeviceAndSwapChain
// ---------------------------------------------------------------------------
typedef HRESULT(WINAPI *D3D11CreateDeviceAndSwapChain_t)(
    IDXGIAdapter *pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software,
    UINT Flags, const D3D_FEATURE_LEVEL *pFeatureLevels, UINT FeatureLevels,
    UINT SDKVersion, const DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
    IDXGISwapChain **ppSwapChain, ID3D11Device **ppDevice,
    D3D_FEATURE_LEVEL *pFeatureLevel, ID3D11DeviceContext **ppImmediateContext);

HRESULT WINAPI stub_D3D11CreateDeviceAndSwapChain(
    IDXGIAdapter *pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software,
    UINT Flags, const D3D_FEATURE_LEVEL *pFeatureLevels, UINT FeatureLevels,
    UINT SDKVersion, const DXGI_SWAP_CHAIN_DESC *pSwapChainDesc,
    IDXGISwapChain **ppSwapChain, ID3D11Device **ppDevice,
    D3D_FEATURE_LEVEL *pFeatureLevel,
    ID3D11DeviceContext **ppImmediateContext) {
  static D3D11CreateDeviceAndSwapChain_t realFunc =
      (D3D11CreateDeviceAndSwapChain_t)GetProcAddress(
          LoadLibraryA("d3d11.dll"), "D3D11CreateDeviceAndSwapChain");
  return realFunc(pAdapter, DriverType, Software, Flags, pFeatureLevels,
                  FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain,
                  ppDevice, pFeatureLevel, ppImmediateContext);
}

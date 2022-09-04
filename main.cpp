#include "App.h"
#include "pch.h"

using namespace winrt;
using namespace winrt::Windows::UI::Xaml;
using namespace uwp_cmake;

int __stdcall wWinMain() {
  init_apartment();
  Application::Start([](auto&&) { make<App>(); });
}

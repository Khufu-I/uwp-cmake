#include <string>

#include "pch.h"

#ifndef UWP_CMAKE_APP
#define UWP_CMAKE_APP

namespace uwp_cmake {
struct App : winrt::Windows::UI::Xaml::ApplicationT<App> {
 private:
  std::wstring m_text = L"";

  void render();

 public:
  void OnLaunched(winrt::Windows::ApplicationModel::Activation::
                      LaunchActivatedEventArgs const&);
};
}  // namespace uwp_cmake

#endif  // UWP_CMAKE_APP
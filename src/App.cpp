#include "App.h"

#include <string>

using namespace winrt;
using namespace winrt::Windows::ApplicationModel::Activation;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::UI::Text;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::UI::Xaml::Media;

namespace uwp_cmake {
auto outputString(const std::wstring& text) {
  return text == L"" ? L"Hello World" : text;
}

void App::OnLaunched(LaunchActivatedEventArgs const&) {
  render();
  Window::Current().Activate();
}

void App::render() {
  TextBlock output;
  output.Text(outputString(m_text));
  output.Style(
      Resources().TryLookup(box_value(L"HeaderTextBlockStyle")).as<Style>());
  output.TextAlignment(TextAlignment::Center);
  output.TextWrapping(TextWrapping::WrapWholeWords);

  TextBox input;
  input.Header(box_value(L"Enter Text"));
  input.Text(m_text);
  input.Margin({20, 20, 20, 20});
  input.TextChanged([=](const auto& /*sender*/, const auto& /*event*/) {
    m_text = input.Text();
    output.Text(outputString(m_text));
  });

  StackPanel vStack;
  vStack.VerticalAlignment(VerticalAlignment::Center);
  vStack.Children().Append(input);
  vStack.Children().Append(output);

  // Refresh button only shown in Debug mode
#ifdef _DEBUG
  Button refreshButton;
  refreshButton.Content(box_value(L"Refresh"));
  refreshButton.HorizontalAlignment(HorizontalAlignment::Center);
  refreshButton.Margin({20, 20, 20, 20});
  refreshButton.Click(
      [this](const auto& /*sender*/, const auto& /*event*/) { render(); });
  vStack.Children().Append(refreshButton);
#endif

  Window::Current().Content(vStack);
}
}  // namespace uwp_cmake
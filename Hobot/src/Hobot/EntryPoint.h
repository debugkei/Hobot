#pragma once

#ifdef _HOBOT_PLATFORM_WINDOWS_

extern Hobot::Application* Hobot::CreateApplication();

int main(int argc, char** argv) {

  auto app = Hobot::CreateApplication();
  
  app->Run();

  delete app;
}

#endif
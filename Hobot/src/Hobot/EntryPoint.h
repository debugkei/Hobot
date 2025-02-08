#pragma once

#ifdef _HOBOT_PLATFORM_WINDOWS_

extern Hobot::Application* Hobot::CreateApplication();

int main(int argc, char** argv) {

  LOG_ERROR("Insane Error");
  LOG_WARNING("Insane Warning");
  LOG_INFO("Insane Info");
  LOG_SUCCESS("Insane Success");

  CORE_LOG_ERROR("Insane Error on engine");
  CORE_LOG_WARNING("Insane Warning on engine");
  CORE_LOG_INFO("Insane Info on engine");
  CORE_LOG_SUCCESS("Insane Success on engine");

  auto app = Hobot::CreateApplication();
  
  app->Run();

  delete app;
}

#endif
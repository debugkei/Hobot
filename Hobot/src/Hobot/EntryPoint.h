#pragma once

#ifdef _HOBOT_PLATFORM_WINDOWS_

extern Hobot::Application* Hobot::CreateApplication();

int main(int argc, char** argv) {

  HOBOT_CWError("Insane Error");
  HOBOT_CWWarning("Insane Warning");
  HOBOT_CWInfo("Insane Info");
  HOBOT_CWSuccess("Insane Success");

  HOBOT_CORE_CWError("Insane Error on engine");
  HOBOT_CORE_CWWarning("Insane Warning on engine");
  HOBOT_CORE_CWInfo("Insane Info on engine");
  HOBOT_CORE_CWSuccess("Insane Success on engine");

  auto app = Hobot::CreateApplication();
  
  app->Run();

  delete app;
}

#endif
#include<Hobot.h>

class Sandbox : public Hobot::Application {};

Hobot::Application* Hobot::CreateApplication() {
  return new Sandbox();
}
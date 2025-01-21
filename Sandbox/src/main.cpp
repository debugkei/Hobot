#include<Hobot.h>

class Sandbox : public Hobot::Application {
private:

public:

};

Hobot::Application* Hobot::CreateApplication() {
  return new Sandbox();
}
#include<Hobot.h>

class Sandbox : public Hobot::Application {
private:

public:
  ~Sandbox() override = default;
};

Hobot::Application* Hobot::CreateApplication() {
  return new Sandbox();
}
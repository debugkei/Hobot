#include<Hobot.h>

struct TestLayer : Hobot::Layer{
  TestLayer() : Layer("Test") {}
  inline void OnUpdate() override { LOG_INFO("TestLayer: Update"); }
  void OnEvent(const Hobot::Event& event) override{
    LOG_INFO(event);
  }
};

class Sandbox : public Hobot::Application {
  private:

  public:
  ~Sandbox() override = default;
  Sandbox() { PushLayer(new TestLayer()); }
};

Hobot::Application* Hobot::CreateApplication() {
  return new Sandbox();
}
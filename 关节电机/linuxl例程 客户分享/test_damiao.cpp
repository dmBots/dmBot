#include "damiao.h"
#include <cmath>

int main(int argc , char** argv)
{
  auto serial = std::make_shared<SerialPort>("/dev/ttyACM0", B921600);

  auto dm = std::make_shared<damiao::Motor>(serial);

  dm->addMotor(0x01, 0x00); // default id
  dm->addMotor(0x02, 0x12);

  dm->zero_position(0x01);
  dm->zero_position(0x02);

  // dm->enable(0x01);
  // dm->enable(0x02);

  // while (true)
  // {
  //   float q = sin(std::chrono::system_clock::now().time_since_epoch().count() / 1e9);

  //   dm->control(0x01, 0, 0, 0, 0, 0);
  //   dm->control(0x02, 0, 0, 0, 0, 0);
  //   // dm->control(0x01, 50, 0.3, q, 0, 0);
  //   // dm->control(0x02, 50, 0.3, q, 0, 0);

  //   // auto & m1 = dm->motors[0x01];
  //   // std::cout << "m1: " << m1->state.q << " " << m1->state.dq << " " << m1->state.tau << std::endl;
  //   // auto & m2 = dm->motors[0x02];
  //   // std::cout << "m2: " << m2->state.q << " " << m2->state.dq << " " << m2->state.tau << std::endl;
  // }

  return 0;
}
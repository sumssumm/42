#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), mTarget(target) {
static bool initialized = false;
    if (!initialized) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        initialized = true;
    }
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::action() const {
  std::cout << "Drilling noises..." << std::endl;
  if (std::rand() % 2 == 0)
    std::cout << mTarget << " has been robotomized successfully!" << std::endl;
  else
    std::cout << "The robotomy failed..." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm(), mTarget("defualt") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
    : AForm(r), mTarget(r.mTarget) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& r) {
  if (this != &r) {
    AForm::operator=(r);
    mTarget = r.mTarget;
  }
  return *this;
}
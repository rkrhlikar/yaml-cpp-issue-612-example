#include "yaml-cpp/yaml.h"

int main(int argc, char** argv)
{
  YAML::Node file = YAML::LoadFile("../test.yaml");
  return 0;
}

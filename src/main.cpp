#include "yaml-cpp/yaml.h"

int main(int argc, char** argv)
{
  YAML::Node file = YAML::LoadFile("config.yaml");
  return 0;
}

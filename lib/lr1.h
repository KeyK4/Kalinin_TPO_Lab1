#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <tuple>

std::tuple<float, float, std::string> sumAndProd(std::ifstream &fin, int b, int d, std::string protocolName);
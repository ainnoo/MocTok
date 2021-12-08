#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <memory>
#include <string>
#include <vector>

#include "common/define.h"

class Generator {
 public:
  Generator(const std::string& file);
  ~Generator();
  Generator(const Generator&) = delete;

 private:
  // Generate Action judging code from Policy.
  std::unique_ptr<std::string> CreateFromFilter();

  // Construct XDP program.
  void Construct();

  // Write XDP program to |output_filepath_|.
  void Write();

  std::string xdp_prog_;

  std::string yaml_filepath_;

  std::vector<Filter> filters_;

  std::string output_filepath_ = "xdp-generated.c";
};

#endif  // GENERATOR_H_

#include <vector>


class letter_matrix {
  std::vector<std::vector<bool> >m_;
public:
  letter_matrix(unsigned int x, unsigned int y) {
    m_.resize(x, std::vector<bool>(y,false));
  }
  class matrix_row {
    std::vector<bool>& row_;
  public:
    matrix_row(std::vector<bool>& r) : row_(r) {
    }
    const bool& operator[](unsigned int y) {
      return row_.at(y);
    }
  };
  const matrix_row& operator[](unsigned int x) {
    return matrix_row(m_.at(x));
  }
};
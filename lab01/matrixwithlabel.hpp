//
//  matrixwithlabel.hpp
//  lab01
//
//  Created by Jakub Matysek on 04/03/2024.
//

#ifndef matrixwithlabel_hpp
#define matrixwithlabel_hpp

#include "matrix.hpp"
#include <initializer_list>

class MatrixWithLabel : public Matrix {
    std::string label { "A" };

public:
    using Matrix::Matrix;

    MatrixWithLabel(const std::string& label, const size_t N, const size_t M);

    MatrixWithLabel(const std::string& label,
        const std::initializer_list<std::initializer_list<double>>& data);

    MatrixWithLabel(const MatrixWithLabel& matrix);

    MatrixWithLabel(MatrixWithLabel&& matrix) = default;

    MatrixWithLabel& operator=(MatrixWithLabel& matrix) = default;

    MatrixWithLabel& operator=(MatrixWithLabel&& matrix) = default;

    auto getLabel() -> std::string;

    void setLabel(const std::string& label);
};

#endif /* matrixwithlabel_hpp */

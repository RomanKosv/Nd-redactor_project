#ifndef LINEAR_GEOMETRY_H
#define LINEAR_GEOMETRY_H

#include <optional>

template<typename Dim>
class Space
{
public:
    Dim new_dim()=0;
};
template<typename DimIn,
         typename IntersectIn,
         typename IntersectOut,
         typename UnionIn,
         typename UnionOut,
         typename Scalar,
         typename Vector>
class LinearGeometrySystem{

};

#endif // LINEAR_GEOMETRY_H

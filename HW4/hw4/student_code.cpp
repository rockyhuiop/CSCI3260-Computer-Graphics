
/*
Type your name and student ID here
	- Name: HUI Rocky  
	- Student ID: 1155172012
*/

#include "bezierPatch.h"
#include "bezierCurve.h"

  /**
   * Evaluates one step of the de Casteljau's algorithm using the given points and
   * the scalar parameter t (class member).
   *
   * @param points A vector of points in 2D
   * @return A vector containing intermediate points or the final interpolated vector
   */
  std::vector<glm::vec2> BezierCurve::evaluateStep(std::vector<glm::vec2> const &points)
  { 
      // TODO Part 1.
      std::vector<glm::vec2> newPoints;

      for (size_t i = 0; i < points.size() - 1; i++)
      {
          // de Casteljau Algorithm
          glm::vec2 point = (1 - t) * points[i] + t * points[i + 1];

          // Add to list
          newPoints.push_back(point);
      }

      return newPoints;
  }

  /**
   * Evaluates one step of the de Casteljau's algorithm using the given points and
   * the scalar parameter t (function parameter).
   *
   * @param points    A vector of points in 3D
   * @param t         Scalar interpolation parameter
   * @return A vector containing intermediate points or the final interpolated vector
   */
  std::vector<glm::vec3> BezierPatch::evaluateStep(std::vector<glm::vec3> const &points, float t) const
  {
      // TODO Part 2.
      std::vector<glm::vec3> newPoints;

      for (size_t i = 0; i < points.size() - 1; i++)
      {
          // de Casteljau Algorithm
          glm::vec3 point = (1 - t) * points[i] + t * points[i + 1];

          // Add to list
          newPoints.push_back(point);
      }

      return newPoints;
  }

  /**
   * Fully evaluates de Casteljau's algorithm for a vector of points at scalar parameter t
   *
   * @param points    A vector of points in 3D
   * @param t         Scalar interpolation parameter
   * @return Final interpolated vector
   */
  glm::vec3 BezierPatch::evaluate1D(std::vector<glm::vec3> const &points, float t) const
  {
      // TODO Part 2.
      std::vector<glm::vec3> newPoints = points;

      // Evaluate until only one point left
      while (newPoints.size() > 1)
      {
          newPoints = evaluateStep(newPoints, t);
      }

      // The last point
      return newPoints[0];
  }

  /**
   * Evaluates the Bezier patch at parameter (u, v)
   *
   * @param u         Scalar interpolation parameter
   * @param v         Scalar interpolation parameter (along the other axis)
   * @return Final interpolated vector
   */
  glm::vec3 BezierPatch::evaluate(float u, float v) const 
  {  
      // TODO Part 2.
      std::vector<glm::vec3> points;

      for (const auto& controlPoint : controlPoints)
      {
          points.push_back(evaluate1D(controlPoint, u));
      }

      return evaluate1D(points, v);
  }


void compute_triangle_normal(glm::vec3& p0, glm::vec3& p1, glm::vec3& p2, glm::vec3& n)
{
    //TODO Part 3. 
    // Return the surface normal of a triangle with vertices at (p0, p1, p2)
  
    // Triangle
    glm::vec3 v0 = p1 - p0;
    glm::vec3 v1 = p2 - p0;

    // Cross product
    n = glm::cross(v0, v1);
    n = glm::normalize(n);
}

/*
  glm::vec3 Vertex::normal( void ) const
  {
    // TODO Part 3.
    // Returns an approximate unit normal at this vertex, computed by
    // taking the area-weighted average of the normals of neighboring
    // triangles, then normalizing.
    return glm::vec3();
  }
  */
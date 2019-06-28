#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include <iostream>
#include <vector>
#include <string>
#include "route_model.h"


class RoutePlanner {
  public:
    RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y);
  	void AStarSearch();
    // Add public variables or methods declarations here.
  	float GetDistance(){return distance;}

  private:
    // Add private variables or methods declarations here.
  	RouteModel::Node* start_node;
  	RouteModel::Node* end_node;
  	float distance;
    RouteModel &m_Model;
    std::vector<RouteModel::Node *> open_list;
    RouteModel::Node* NextNode();
    std::vector<RouteModel::Node>ConstructFinalPath(RouteModel::Node *);
  	float CalculateHValue(const RouteModel::Node *);
  	void AddNeighbors(RouteModel::Node *);
};

#endif
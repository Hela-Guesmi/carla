// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/road/InformationSet.h"
#include "carla/road/RoadTypes.h"

#include <vector>
#include <memory>

namespace carla {
namespace road {

  class LaneSection;

  class Lane : private MovableNonCopyable {
  public:

    Lane(
      LaneSection *lane_section,
      LaneId id,
      std::vector<std::unique_ptr<element::RoadInfo>> &&info)
      : _lane_section(lane_section),
        _id(id),
        _info(std::move(info)) {}

    Lane(Lane &&) = default;
    Lane &operator=(Lane &&) = default;

    LaneSection *GetLaneSection() const;

    LaneId GetId() const;

  private:

    LaneSection *_lane_section;

    LaneId _id;

    InformationSet _info;

  };

} // road
} // carla

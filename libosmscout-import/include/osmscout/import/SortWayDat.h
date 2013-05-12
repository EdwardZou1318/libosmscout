#ifndef OSMSCOUT_IMPORT_SORTWAYDAT_H
#define OSMSCOUT_IMPORT_SORTWAYDAT_H

/*
  This source is part of the libosmscout library
  Copyright (C) 2013  Tim Teulings

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

#include <osmscout/import/SortDat.h>

#include <osmscout/Way.h>

namespace osmscout {

  class SortWayDataGenerator : public SortDataGenerator<Way>
  {
  private:
    void GetTopLeftCoordinate(const Way& data,
                              double& maxLat,
                              double& minLon)
    {
      maxLat=data.nodes[0].GetLat();
      minLon=data.nodes[0].GetLon();

      for (size_t n=1; n<data.nodes.size(); n++) {
        maxLat=std::max(maxLat,data.nodes[n].GetLat());
        minLon=std::min(minLon,data.nodes[n].GetLon());
      }
    }

  public:
    SortWayDataGenerator()
    : SortDataGenerator<Way>("ways.dat","ways.idmap")
    {
      AddSource(OSMRefType::osmRefWay,"wayway.dat");
    }

    std::string GetDescription() const
    {
      return "Sort/copy ways";
    }
  };

}

#endif

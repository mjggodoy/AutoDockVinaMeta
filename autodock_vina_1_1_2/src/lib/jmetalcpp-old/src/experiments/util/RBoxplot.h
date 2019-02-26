//  RBoxplot.h
//
//  Author:
//       Esteban López-Camacho <esteban@lcc.uma.es>
//
//  Copyright (c) 2011 Antonio J. Nebro, Juan J. Durillo
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef __RBOXPLOT__
#define __RBOXPLOT__

#include <string>
#include <FileUtils.h>
#include <ExperimentReport.h>

class ExperimentReport;

/**
 * Class for generating results in form of boxplots
 */

class RBoxplot {
public:
  static void generateScripts(int rows, int cols, vector<string> problems,
      string prefix, bool notch, ExperimentReport * experiment);
};

#endif /* __RBOXPLOT__ */

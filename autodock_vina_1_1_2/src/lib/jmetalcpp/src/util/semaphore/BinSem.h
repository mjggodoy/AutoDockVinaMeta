//  BinSem.h
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

#ifndef __BIN_SEM__
#define __BIN_SEM__


#include <mutex>
#include <condition_variable>


/**
 * This class implements a binary semaphore for C++11
 */
class BinSem {

private:
    static const int count_max;
    int count_;
    std::mutex m_;
    std::condition_variable cv_;
  
public:
  explicit BinSem(int init_count = count_max);
  void wait();
  bool try_wait();
  void signal();
  void lock();
  bool try_lock();
  void unlock();
  
};


#endif

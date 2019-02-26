//  BinSem.cpp
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


#include <BinSem.h>


/**
 * This class implements a binary semaphore for C++11
 */

const int BinSem::count_max = 1;

/**
 * Constructor.
 */
BinSem::BinSem(int init_count) {
  count_ = init_count;
}

void BinSem::wait() {
  std::unique_lock<std::mutex> lk(m_);
  cv_.wait(lk, [=]{ return 0 < count_; });
  --count_;
}

bool BinSem::try_wait() {
  std::lock_guard<std::mutex> lk(m_);
  if (0 < count_) {
    --count_;
    return true;
  } else {
    return false;
  }
}

void BinSem::signal() {
  std::lock_guard<std::mutex> lk(m_);
  if (count_ < count_max) {
    ++count_;
    cv_.notify_one();
  }
}

void BinSem::lock() {
  wait();
}

bool BinSem::try_lock() {
  return try_wait();
}

void BinSem::unlock() {
  signal();
}
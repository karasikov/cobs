/*******************************************************************************
 * cobs/settings.cpp
 *
 * Copyright (c) 2019 Timo Bingmann
 *
 * All rights reserved. Published under the MIT License in the LICENSE file.
 ******************************************************************************/

#include <cobs/settings.hpp>

#include <thread>

namespace cobs {

size_t gopt_threads = std::thread::hardware_concurrency();

bool gopt_keep_temporary = false;

} // namespace cobs

/******************************************************************************/

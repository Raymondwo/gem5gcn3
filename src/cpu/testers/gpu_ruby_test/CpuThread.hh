/*
 * Copyright (c) 2017 Advanced Micro Devices, Inc.
 * All rights reserved.
 *
 * For use for simulation and test purposes only
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Tuan Ta
 */

#ifndef CPU_TESTERS_PROTOCOL_TESTER_CPUTHREAD_HH_
#define CPU_TESTERS_PROTOCOL_TESTER_CPUTHREAD_HH_

#include "cpu/testers/gpu_ruby_test/Thread.hh"
#include "params/CpuThread.hh"
#include "sim/clocked_object.hh"

class CpuThread : public Thread
{
  public:
    typedef CpuThreadParams Params;
    CpuThread(const Params *p);
    virtual ~CpuThread();

    typedef AddressManager::Location Location;
    typedef AddressManager::Value Value;

    void hitCallback(PacketPtr pkt);

  protected:
    void issueLoadOps();
    void issueStoreOps();
    void issueAtomicOps();
    void issueAcquireOp();
    void issueReleaseOp();
};

#endif /* CPU_TESTERS_PROTOCOL_TESTER_CPUTHREAD_HH_ */

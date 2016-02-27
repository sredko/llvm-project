//===- CGSCCPassManager.cpp - Managing & running CGSCC passes -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "llvm/Analysis/CGSCCPassManager.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

// Explicit instantiations for the core proxy templates.
namespace llvm {
template class InnerAnalysisManagerProxy<CGSCCAnalysisManager, Module>;
template class OuterAnalysisManagerProxy<ModuleAnalysisManager,
                                         LazyCallGraph::SCC>;
template class InnerAnalysisManagerProxy<FunctionAnalysisManager,
                                         LazyCallGraph::SCC>;
template class OuterAnalysisManagerProxy<CGSCCAnalysisManager, Function>;
}

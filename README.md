# Parallel Computing

CERN STEAM Academy 2026 — course repository.

**Conveners / speakers:** Tim Mattson (Human Learning Group)

## Overview

In this course, we will cover the core concepts in parallel computing that
anyone working in scientific computing should know.   We will cover these 
concepts through ``hands-on'' learning.  

To minimize time spent learning a new application programming interface (API),
we will work with the simplest parallel programing API used in scientific
computing: OpenMP. It's also the most commonly used API for parallel computing in 
the sciences.

OpenMP is mostly focussed on multithreaded programming for CPUs.  It is 
important to appreciate, however, that the concepts we'll cover apply
to the full range of parallel programming APIs and platforms 
used in scientific computing.   After we finish discussing OpenMP for CPUs, 
we'll briefly discuss how OpenMP can be used for GPUs.  Then we will
complete our survey of parallelism in scientific computing by discussing
MPI and its use for programming clusters.

We'll close the course with a short lecture on pseudo random numbers: what they
are and how to safely use them in computational physics.

## Environment setup

This course runs on the academy laptops (AlmaLinux 9). For the shared environment —
accounts, WiFi, editors, lxplus, AFS, CERNBox — see the
[STEAM Academy documentation](https://stac.docs.cern.ch/).

OpenMP is included in all modern gnu and clang compilers.  The one exception is
Apple.  They want to force people to use their proprietary parallel programming
environment so they removed OpenMP from the clang compiler used in their
xcode tools.   Making matters worse, Apple names its default clang compiler
''gcc``; hence you may think you're using a gnu compiler on an Apple laptop
even when using their damaged clang compiler. 

What most of us working in scientific computing do on our Apple laptops is 
use our prefered package manager (such as homebrew) to load actual gnu compilers.
If you do this, however, you'll need to use the fully resolved name for the 
compiler (such as gcc-16 ... where the number varies depending on the 
version of the compiler).

If you want to experiment with GPU programming, Nvidia support for OpenMP is
excellent.  You need to load, however, their HCP toolkit in order to 
access their OpenMP (and OpenACC) compilers.


```sh
# make a compiler available (e.g. a CERN LCG build via environment modules)
module load <compiler>

# get the code
git clone https://github.com/CERN-STEAM-Academy/26-PARALLEL-COMPUTING.git
cd 26-PARALLEL-COMPUTING

# configure / build / run
```

## Materials

The lectures are found in three pdf files:

* OpenMP_CPU.pdf
* Par_Beyond_CPU.pdf
* Random_use_and_abuse.pdf.

Exercises with solutions and additional challenge problems for 
self-study are in the following directory:

* OMP_CPU_Exercises

The following is the permanent repository for my full set of parallel 
programming courses:

* https://github.com/tgmattso/ParProgForPhys.git

I continuously update this repository.
 
## Schedule

See the [Indico timetable](https://indico.cern.ch/event/1697464/timetable).

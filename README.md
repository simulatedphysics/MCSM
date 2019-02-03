# Monte Carlo for Statistical Mechanics

The goal of this project is to simulate physics in lattice systems. The first system we study here is the nearest neighbor Ising model.
It can be shown analytically that the ferromagnetic state is the ground state of the nearest neighbor Ising model. The state is shown here.

<p align="center">
<img src="Figures/ferromagnetic_state.png">
  </p>

The ferromagnetic state can be obtained in simulation by allowing the Monte Carlo to accept energy changes that both lower the energy as well as leave the energy unchanged. This does not always yield a ferromagnetic state, though. There are states that cannot be changed by this acceptance criterion. These states involve thick stripes that run all the way across the system. One such state is shown here.

<p align="center">
<img src="Figures/ising.png">
  </p>

We have attemped to use simulated annealing to find the ferromagnetic ground state of the system, but the system cannot reach the ground state with this method current. We are investigating this, because our intuition is that it should be possible to obtain the ground state with simulated annealing.

The next model we will study is the classical Heisenberg model. We will study the nearest neighbor contribution.

# 2D-FEM-solver-code
Steady-state temperature distribution on a 2D rectangular plate with Dirichlet boundary conditions using FEM in C programming

## Problem
<p align="center">
  <img src="https://github.com/Vire-YR/2D-FEM-solver-code/blob/master/problem.png" width="300" height="300"/>
</p>

### Define Geometry
   * A rectangular block was defined using Length and Height parameters.
### Discretization
   * The defined geometry was divided into finite number of elements. The size of each element is same throughout.
### Initialization
   * An initial temperature value was assigned to each of the nodes. In this case, the initial value was taken to be 0K at all nodes.
### Assigning dirichlet boundary conditions
   * The constant temperature at the 4 walls of the rectangular plate was assigned. This was done by changing the temperature values at each of the nodes at the walls.
### FEM Solution simulation
   * Gauss Seidel second order central difference method was used to solve the FEM model.
   * A succesive over relaxation of w = 1.8 was used to accelerate the solution.
   * The convergence criteria was used as a residual error of less than 0.01
   
 Governing equation for steady 2D heat conduction (which if there is no heat generation is a Laplace equation):
<p align="center">
 <img src="https://github.com/Vire-YR/2D-FEM-solver-code/blob/master/equation.JPG" width="200" height="100"/>
</p>

### Analytical solution
   * The analytical solution was also found using the following formula. Here n was varied from 1 to 110 for getting more accurate result.
<p align="center">
 <img src="https://github.com/Vire-YR/2D-FEM-solver-code/blob/master/analytical.JPG" width="500" height="150"/>
</p>

### Tabulating values
   * The results obtained at the vertical mid of the plate were tabulated and Gauss Seidel, Succesive Over Relaxation and Analytical values were compared. 
### Exporting the values
   * The same was exported as an external excel file wherein the following graph for Gauss Seidel was obtained.
 <p align="center">
 <img src="https://github.com/Vire-YR/2D-FEM-solver-code/blob/master/graph.png" width="600" height="400"/>
</p>

# This test is used to verify the density_water output of the waterAndSteamEquationOfStatePT 
# function in the WaterSteamEOS UserObject.  A combination of incremented pressures and 
# temperatures are inputed into the EOSWaterAndSteamPTFuncPPS and the water density is outputted.  
# The results are compared to a csv file which contains IAWPS97 water and steam formulation data
[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 10
  ny = 10
[]

[Variables]
  [./u]
  [../]
[]

[Functions]
  active = 'temperature_function'
  [./temperature_function]
    type = ParsedFunction
    value = 10+20*t
  [../]
[]

[Kernels]
  [./diff]
    type = Diffusion
    variable = u
  [../]
  [./time_yipee]
    type = TimeDerivative
    variable = u
  [../]
[]

[BCs]
  [./left]
    type = DirichletBC
    variable = u
    boundary = left
    value = 0
  [../]
  [./right]
    type = DirichletBC
    variable = u
    boundary = right
    value = 1
  [../]
[]

[UserObjects]
  [./water_steam_properties]
    type = WaterSteamEOS
  [../]
[]

[Postprocessors]
 [./density_2MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 2e6
 temperature_value = temperature_function
 [../]
 
 [./density_3MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 3e6
 temperature_value = temperature_function
 [../]
 
 [./density_4MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 4e6
 temperature_value = temperature_function
 [../]
 
 [./density_5MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 5e6
 temperature_value = temperature_function
 [../]
 
 [./density_6MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 6e6
 temperature_value = temperature_function
 [../]
 
 [./density_7MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 7e6
 temperature_value = temperature_function
 [../]
 
 [./density_8MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 8e6
 temperature_value = temperature_function
 [../]
 
 [./density_9MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 9e6
 temperature_value = temperature_function
 [../]
 
 [./density_10MPa]
 type = EOSWaterAndSteamPTFuncPPS
 water_steam_properties = water_steam_properties
 pressure_value = 10e6
 temperature_value = temperature_function
 [../]
 
 []

[Executioner]
  type = Transient
  num_steps = 10
  dt = 1
  petsc_options = -snes_mf_operator
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
  nl_abs_tol = 1e-5
  end_time = 1000000
[]

[Output]
  output_initial = true
  postprocessor_csv = true
  exodus = false
  perf_log = true
[]

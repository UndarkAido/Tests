cmake_minimum_required (VERSION 3.6)

function(run_command PARAMS)
  execute_process(${PARAMS})
endfunction(run_on_install)

set(PARAMS_IN pwd )
run_command
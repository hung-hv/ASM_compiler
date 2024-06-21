# Define the command
$command_cmake = 'cmake .. -G "MinGW Makefiles"'

# Execute the command
Invoke-Expression $command_cmake

$command_make = 'MinGW32-make'
# Execute the command
Invoke-Expression $command_make
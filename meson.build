project('fmm', 'cpp',
    version : '0.0.1',
    default_options : ['warning_level=3',
                     'b_coverage=true',
                     'cpp_std=c++14'])

subdir('src')

# === custom commands ===
run_target('cov',
    command : ['./build_scripts/generate_coverage_report'])

run_target('clang-tidy',
    command: ['./build_scripts/tidy.sh'])

run_target('cppcheck', command : ['cppcheck', 
    '--enable=all', '--std=c++14', '--error-exitcode=1', '--suppress=missingInclude',
    'src', 'test'])
# === end custom commands ===

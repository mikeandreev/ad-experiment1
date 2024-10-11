#pragma once

extern int enzyme_dup;
//extern int enzyme_dupnoneed;
//extern int enzyme_out;
extern int enzyme_const;

template <typename Retval, typename... Args>
Retval __enzyme_autodiff(Retval (*)(Args...), auto...);


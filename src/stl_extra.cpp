
#include <chaiscript/chaiscript.hpp>
#include <list>
#include <string>

// MSVC doesn't like that we are using C++ return types from our C declared module
// but this is the best way to do it for cross platform compatibility
#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable : 4190)
#endif

#ifdef __llvm__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif

CHAISCRIPT_MODULE_EXPORT chaiscript::ModulePtr create_chaiscript_module_stl_extra()
{
  return chaiscript::bootstrap::standard_library::list_type<std::list<chaiscript::Boxed_Value> >("List");
}

#ifdef __llvm__
#pragma clang diagnostic pop
#endif

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

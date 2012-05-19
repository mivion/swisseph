{
  'targets': [
    {
      'target_name': 'swisseph',
      'type': 'static_library',
      'direct_dependent_settings': {
        'include_dirs': ['.'],
      },
      'sources': [
        'swecl.cc',
        'swedate.cc',
        'swehel.cc',
        'swehouse.cc',
        'swejpl.cc',
        'swemmoon.cc',
        'swemplan.cc',
        'sweph.cc',
        'swephlib.cc'
      ]
    }
  ]
}
{
  'targets': [
    {
      'target_name': 'swissephz',
      'type': 'static_library',
      'direct_dependent_settings': {
        'include_dirs': ['.']
      },
      'sources': [
        'swecl.c',
        'swedate.c',
        'swehel.c',
        'swehouse.c',
        'swejpl.c',
        'swemmoon.c',
        'swemplan.c',
        'sweph.c',
        'swephlib.c'
      ]
    }
  ]
}
{
  'targets': [
    {
      'target_name': 'swisseph',
      'sources': [
        'src/util.cc',
        'src/date.cc',
        'src/swisseph.cc',
        'src/callback.cc',
        'src/pos.cc',
        'src/hel.cc',
        'src/house.cc',
        'src/eclipse.cc'
      ],
      'dependencies': [
      	'deps/swisseph/swisseph.gyp:swissephz'
      ],
      "include_dirs": ["<!(node -e \"require('nan')\")"]
    }
  ]
}

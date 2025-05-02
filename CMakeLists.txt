if ((NOT CONFIG_ZMK_SPLIT) OR CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
  target_sources_ifdef(ZMK_BEHAVIOR_SYSOFF app PRIVATE src/behaviors/behavior_sysoff.c)

  zephyr_include_directories(include)
endif()

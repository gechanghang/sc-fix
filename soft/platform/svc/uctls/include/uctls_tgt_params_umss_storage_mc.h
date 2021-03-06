// =============================================================================
// TGT_UCTLS_CONFIG
// -----------------------------------------------------------------------------
/// List of services
// =============================================================================
#ifndef TGT_UCTLS_CONFIG

#define TGT_UCTLS_CONFIG                                                \
{                                                                       \
    {                                                                   \
        .servicesList[0] =                                              \
        {                                                               \
            .serviceCallback = &g_utracesCallback,                      \
        }                                                               \
    },                                                                  \
    {                                                                   \
        .servicesList[0] =                                              \
        {                                                               \
            .serviceCallback = &g_umssCallback,                         \
            .serviceCfg      =                                          \
            {                                                           \
                .mss.transportCfg =                                     \
                {                                                       \
                    .transportParameters =                              \
                    {                                                   \
                        .inEpNum  = 2,                                  \
                        .outEpNum = 2                                   \
                    },                                                  \
                    .transportCallback = &g_umssTransportBoScsiCallback \
                },                                                      \
                .mss.storageCfg =                                       \
                {                                                       \
                    {                                                   \
                        .storageCallback = &g_umssStorageMcCallback     \
                    },                                                  \
                    {                                                   \
                        .storageCallback        = 0,                    \
                        .storageParameters.size = 0                     \
                    },                                                  \
                    {                                                   \
                        .storageCallback        = 0,                    \
                        .storageParameters.size = 0                     \
                    },                                                  \
                    {                                                   \
                        .storageCallback        = 0,                    \
                        .storageParameters.size = 0                     \
                    }                                                   \
                }                                                       \
            }                                                           \
        }                                                               \
    },                                                                  \
    {                                                                   \
        .servicesList[0].serviceCallback = 0                            \
    }                                                                   \
}

#endif // TGT_UCTLS_CONFIG


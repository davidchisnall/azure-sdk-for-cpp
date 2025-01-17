// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

/**
 * @file
 * @brief Keyvault Deleted Secret definition
 */

#pragma once
#include <azure/core/datetime.hpp>
#include <azure/keyvault/secrets/keyvault_secret.hpp>

namespace Azure { namespace Security { namespace KeyVault { namespace Secrets {
  /**
   * @brief A Deleted Secret consisting of its previous id, attributes and its tags,
   * as well as information on when it will be purged.
   */
  struct KeyVaultDeletedSecret : public KeyVaultSecret
  {
    /**
     * @brief A Deleted Secret consisting of its previous id, attributes and its tags,
     * as well as information on when it will be purged.
     */
    std::string RecoveryId;

    /**
     * @brief The time when the secret is scheduled to be purged, in UTC.
     */
    Azure::DateTime ScheduledPurgeDate;

    /**
     * @brief The time when the secret was deleted, in UTC.
     */
    Azure::DateTime DeletedDate;

    /**
     * @brief Default constructor.
     */
    KeyVaultDeletedSecret() = default;

    /**
     * @brief Constructor.
     *
     * @param name Name of the deleted secret.
     */
    KeyVaultDeletedSecret(std::string name) : KeyVaultSecret(std::move(name)) {}
  };
}}}} // namespace Azure::Security::KeyVault::Secrets

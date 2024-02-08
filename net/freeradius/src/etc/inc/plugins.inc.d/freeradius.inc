<?php

/*
 * Copyright (C) 2017-2021 Michael Muenz <m.muenz@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

function freeradius_services()
{
    global $config;

    $services = array();

    if (isset($config['OPNsense']['freeradius']['general']['enabled']) && $config['OPNsense']['freeradius']['general']['enabled'] == 1) {
        $services[] = array(
            'description' => gettext('AAA Radius'),
            'configd' => array(
                'restart' => array('AAA Radius restart'),
                'start' => array('AAA Radius start'),
                'stop' => array('AAA Radius stop'),
            ),
            'name' => 'AAA Radius',
            'pidfile' => '/var/run/radiusd/radiusd.pid'
        );
    }

    return $services;
}

function freeradius_xmlrpc_sync()
{
    $result = array();
    $result['id'] = 'freeradius';
    $result['section'] = 'OPNsense.freeradius';
    $result['description'] = gettext('AAA Radius');
    $result['services'] = ["freeradius"];
    return array($result);
}
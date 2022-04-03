/**
 * @file INegotiator.h
 * @author Junchi Zhu
 *
 *
 */
#pragma once

class Rod;

/**
 * Negotiator interface for rod/piston and rod/lever negotiations
 */
class INegotiator
{
public:
    /**
     * Negotiate with a rod to come up with a mutual rotation solution
     * @param rod
     */
    virtual void Negotiate(Rod *rod) = 0;
};

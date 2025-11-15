#include <MD_Math.h>
#include <Constant.h>
#include <stdio.h>

mdQuat QuatAdd(mdQuat q1, mdQuat q2)
{
    mdQuat r_q;
    r_q.a = q1.a + q2.a; r_q.b = q1.b + q2.b; r_q.c = q1.c + q2.c; r_q.d = q1.d + q2.d;
    return r_q;
}

mdQuat QuatMinus(mdQuat q1, mdQuat q2)
{
    mdQuat r_q;
    r_q.a = q1.a - q2.a; r_q.b = q1.b - q2.b; r_q.c = q1.c - q2.c; r_q.d = q1.d - q2.d;
    return r_q;
}

mdQuat QuatDot(mdQuat q1, mdQuat q2)
{
    mdQuat r_q;
    r_q.a = q1.a * q2.a - q1.b * q2.b - q1.c * q2.c - q1.d * q2.d;
    r_q.b = q1.b * q2.a + q1.a * q2.b - q1.d * q2.c + q1.c * q2.d;
    r_q.c = q1.c * q2.a + q1.d * q2.b + q1.a * q2.c - q1.b * q2.d;
    r_q.d = q1.d * q2.a - q1.c * q2.b + q1.b * q2.c + q1.a * q2.d;
    return r_q;
}

mdQuat ScaleQuat(mdQuat q1, float scale)
{
    mdQuat r_q;
    r_q.a = q1.a * scale; r_q.b = q1.b * scale; r_q.c = q1.c * scale; r_q.d = q1.d * scale;
    return r_q;
}

int QuatEqual(mdQuat q1, mdQuat q2)
{
    return (
        MD_Equal(q1.a, q2.a) &&
        MD_Equal(q1.b, q2.b) &&
        MD_Equal(q1.c, q2.c) &&
        MD_Equal(q1.d, q2.d) 
    ) ? MD_TRUE : MD_FALSE;
}

float QuatLength(mdQuat q)
{
    return sqrtf(q.a * q.a + q.b * q.b + q.c * q.c + q.d * q.d);
}

mdQuat QuatNorm(mdQuat q)
{
    float length = 1.0f / QuatLength(q);
    mdQuat r_q;

    r_q.a = q.a * length;
    r_q.b = q.b * length;
    r_q.c = q.c * length;
    r_q.d = q.d * length;

    return r_q;
}

mdQuat QuatConj(mdQuat q)
{
    mdQuat r_q;

    r_q.a = q.a;
    r_q.b = -q.b;
    r_q.c = -q.c;
    r_q.d = -q.d;

    return r_q;
}

mdQuat QuatInv(mdQuat q)
{
    float length = 1.0f / (q.a * q.a + q.b * q.b + q.c * q.c + q.d * q.d);
    mdQuat r_q = QuatConj(q);
    r_q.a = r_q.a * length;
    r_q.b = r_q.b * length;
    r_q.c = r_q.c * length;
    r_q.d = r_q.d * length;
    return r_q;

}

mdQuat QuatFromAxisAngle(mdVec3 axis, float angle)
{
    float halfAngle = angle * 0.5f;
    float sinHalf = sin(halfAngle);
    
    axis = Vec3Norm(axis);

    mdQuat r_q;
    r_q.a = cos(halfAngle);
    r_q.b = axis.x * sinHalf;
    r_q.c = axis.y * sinHalf;
    r_q.d = axis.z * sinHalf;
    return r_q;
}

mdQuat QuatFromMat(mdMat m)
{
    float trace = m._11 + m._22 + m._33;
        mdQuat q;
        
        if (trace > 0.0f) {
            float s = 0.5f / sqrt(trace + 1.0f);
            q.a = 0.25f / s;
            q.b = (m._32 - m._23) * s;
            q.c = (m._13 - m._31) * s;
            q.d = (m._21 - m._12) * s;
        } else {
            if (m._11 > m._22 && m._11 > m._33) {
                float s = 2.0f * sqrt(1.0f + m._11 - m._22 - m._33);
                q.a = (m._32 - m._23) / s;
                q.b = 0.25f * s;
                q.c = (m._12 + m._21) / s;
                q.d = (m._13 + m._31) / s;
            } else if (m._22 > m._33) {
                float s = 2.0f * sqrt(1.0f + m._22 - m._11 - m._33);
                q.a = (m._13 - m._31) / s;
                q.b = (m._12 + m._21) / s;
                q.c = 0.25f * s;
                q.d = (m._23 + m._32) / s;
            } else {
                float s = 2.0f * sqrt(1.0f + m._33 - m._11 - m._22);
                q.a = (m._21 - m._12) / s;
                q.b = (m._13 + m._31) / s;
                q.c = (m._23 + m._32) / s;
                q.d = 0.25f * s;
            }
        }
        
        return QuatNorm(q);
}

mdMat MatFromQuat(mdQuat q)
{
    mdQuat nq = QuatNorm(q);
        float xx = nq.b * nq.b;
        float yy = nq.c * nq.c;
        float zz = nq.d * nq.d;
        float xy = nq.b * nq.c;
        float xz = nq.c * nq.d;
        float yz = nq.d * nq.d;
        float wx = nq.a * nq.b;
        float wy = nq.a * nq.c;
        float wz = nq.a * nq.d;
        
        mdMat m;
        m._11 = 1.0f - 2.0f * (yy + zz);
        m._12 = 2.0f * (xy - wz);
        m._13 = 2.0f * (xz + wy);
        m._14 = 0.0f;
        
        m._21 = 2.0f * (xy + wz);
        m._22 = 1.0f - 2.0f * (xx + zz);
        m._23 = 2.0f * (yz - wx);
        m._24 = 0.0f;
        
        m._31 = 2.0f * (xz - wy);
        m._32 = 2.0f * (yz + wx);
        m._33 = 1.0f - 2.0f * (xx + yy);
        m._34 = 0.0f;
        
        m._41 = 0.0f;
        m._42 = 0.0f;
        m._43 = 0.0f;
        m._44 = 1.0f;
        
        return m;
}

mdVec3 RotateVec(mdQuat q, mdVec3 v)
{
    mdQuat p = {0.0f, v.x, v.y, v.z};
        
        //v' = q * v * q^-1
        mdQuat result = QuatDot(QuatDot(q , p) , QuatInv(q));
        mdVec3 r_v = {result.b, result.c, result.d};
        return r_v;
}

mdQuat QuatSlerp(mdQuat q1, mdQuat q2, float t)
{
    mdQuat from = QuatNorm(q1);
        mdQuat to = QuatNorm(q2);
        
        float dot = from.a * to.a +
        from.b * to.b +
        from.c * to.c +
        from.d * to.d;
        
        if (dot < 0.0f) {
            to.a = -to.a;
            to.b = -to.b;
            to.c = -to.c;
            to.d = -to.d;

            from.a = -from.a;
            from.b = -from.b;
            from.c = -from.c;
            from.d = -from.d;
        }
        
        const float DOT_THRESHOLD = 0.9995f;
        if (dot > DOT_THRESHOLD) {
            return QuatLerp(from, to, t);
        }
        
        dot = MD_Min(MD_Max(dot, -1.0f), 1.0f);
        
        float theta_0 = acos(dot);      
        float theta = theta_0 * t;       
        
        mdQuat q3 = QuatMinus(to , ScaleQuat(from , dot));
        q3 = QuatNorm(q3);
        
        return QuatAdd(ScaleQuat(from , cos(theta)) , ScaleQuat(q3 , sin(theta)));
}

mdQuat QuatLerp(mdQuat q1, mdQuat q2, float t)
{
    mdQuat result = QuatAdd(ScaleQuat(q1 , (1.0f - t)) , ScaleQuat(q2 , t));
    return QuatNorm(result);
}